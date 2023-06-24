#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BOARD_SIZE = 11;

enum class CellState { EMPTY, KING, DEFENDER, ATTACKER, ESCAPE, VALID };

//Posiciones iniciales
vector<vector<CellState>> board(BOARD_SIZE, vector<CellState>(BOARD_SIZE, CellState::EMPTY));
pair<int, int> kingPosition = {5,5}; //Esta siempre se debe actualizar para tener seguimiento del rey
vector<pair<int, int>> defenderPositions = {{3,5},{4,4},{4,5},{4,6},{5,3},{5,4},{5,6},{5,7},{6,4},{6,5},{6,6},{7,5}};
vector<pair<int, int>> attackerPositions = {{0,3},{0,4},{0,5},{0,6},{0,7},{1,5},{3,0},{3,10},{4,0},{4,10},{5,0},{5,1},{5,9},{5,10},{6,0},{6,10},{7,0},{7,10},{9,5},{10,3},{10,4},{10,5},{10,6},{10,7}};
vector<pair<int, int>> escapePositions = {{0,0},{0,10},{10,0},{10,10}};

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = CellState::EMPTY;
        }
    }
    
    for (const auto& pos : defenderPositions)
        board[pos.first][pos.second] = CellState::DEFENDER;

    board[5][5] = CellState::KING;

    for (const auto& pos : attackerPositions)
        board[pos.first][pos.second] = CellState::ATTACKER;
    
    for (const auto& pos : escapePositions)
        board[pos.first][pos.second] = CellState::ESCAPE;
}

void displayBoard() {
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case CellState::EMPTY:
                    cout << ". ";
                    break;
                case CellState::KING:
                    cout << "K ";
                    break;
                case CellState::DEFENDER:
                    cout << "D ";
                    break;
                case CellState::ATTACKER:
                    cout << "A ";
                    break;
                case CellState::ESCAPE:
                    cout << "E ";
                    break;
                case CellState::VALID:
                    cout << "# ";
                    break;
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isValidPosition(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}

void calculateValidMoves(int row, int col) {
    //board[row][col] = CellState::VALID;
    
    //Cálculo para fichas que no sean rey
    if (board[row][col] != CellState::KING){
        // Check vertically
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] != CellState::EMPTY)
                break;
            board[i][col] = CellState::VALID;
        }
        for (int i = row + 1; i < BOARD_SIZE; i++) {
            if (board[i][col] != CellState::EMPTY)
                break;
            board[i][col] = CellState::VALID;
        }

        // Check horizontally
        for (int j = col - 1; j >= 0; j--) {
            if (board[row][j] != CellState::EMPTY)
                break;
            board[row][j] = CellState::VALID;
        }
        for (int j = col + 1; j < BOARD_SIZE; j++) {
            if (board[row][j] != CellState::EMPTY)
                break;
            board[row][j] = CellState::VALID;
        }
    }
    //Cálculo para rey
    if (board[row][col] == CellState::KING) {
        // Check vertically
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] != CellState::EMPTY &&
                board[i][col] != CellState::ESCAPE)
                break;
            board[i][col] = CellState::VALID;
        }
        for (int i = row + 1; i < BOARD_SIZE; i++) {
            if (board[i][col] != CellState::EMPTY &&
                board[i][col] != CellState::ESCAPE)
                break;
            board[i][col] = CellState::VALID;
        }

        // Check horizontally
        for (int j = col - 1; j >= 0; j--) {
            if (board[row][j] != CellState::EMPTY &&
                board[row][j] != CellState::ESCAPE)
                break;
            board[row][j] = CellState::VALID;
        }
        for (int j = col + 1; j < BOARD_SIZE; j++) {
            if (board[row][j] != CellState::EMPTY &&
                board[row][j] != CellState::ESCAPE)
                break;
            board[row][j] = CellState::VALID;
        }
    }
    
}

void highlightValidMoves(int row, int col) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == CellState::VALID)
                board[i][j] = CellState::EMPTY;
        }
    }

    calculateValidMoves(row, col);
}

void restoreBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == CellState::VALID)
                board[i][j] = CellState::EMPTY;
        }
    }
}

CellState getOppositePiece(CellState piece) {
    if (piece == CellState::DEFENDER || piece == CellState::KING) {
        return CellState::ATTACKER;
    } else if (piece == CellState::ATTACKER) {
        return CellState::DEFENDER;
    } else {
        return CellState::EMPTY;
    }
}

void movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    CellState piece = board[fromRow][fromCol];
    board[toRow][toCol] = piece;
    board[fromRow][fromCol] = CellState::EMPTY;

    // Actualizar kingPosition si el rey se mueve
    if (piece == CellState::KING) {
        kingPosition = {};  // Borrar información anterior
        kingPosition = make_pair(toRow, toCol);
    }

    // Verificar si el rey captura un atacante verticalmente
    if (piece == CellState::KING || piece == CellState::DEFENDER) {
        //Arriba
        if (toRow - 1 >= 0 && board[toRow - 1][toCol] == CellState::ATTACKER &&
            toRow - 2 >= 0 &&
            (board[toRow - 2][toCol] == CellState::DEFENDER || board[toRow - 2][toCol] == CellState::KING)) {
            
            board[toRow - 1][toCol] = CellState::EMPTY;
            cout << "Captura realizada!" << endl;
        }
        //Abajo
        if (toRow + 1 < BOARD_SIZE && board[toRow + 1][toCol] == CellState::ATTACKER &&
            toRow + 2 < BOARD_SIZE &&
            (board[toRow + 2][toCol] == CellState::DEFENDER || board[toRow + 2][toCol] == CellState::KING)) {
            
            board[toRow + 1][toCol] = CellState::EMPTY;
            cout << "Captura realizada!" << endl;
        }
    }

    // Verificar si el rey captura un atacante horizontalmente
    if (piece == CellState::KING || piece == CellState::DEFENDER) {
        //Izquierda
        if (toCol - 1 >= 0 && board[toRow][toCol - 1] == CellState::ATTACKER &&
            toCol - 2 >= 0 &&
            (board[toRow][toCol - 2] == CellState::DEFENDER || board[toRow][toCol - 2] == CellState::KING)) {

            board[toRow][toCol - 1] = CellState::EMPTY;
            cout << "Captura realizada!" << endl;
        }
        //Derecha
        if (toCol + 1 < BOARD_SIZE && board[toRow][toCol + 1] == CellState::ATTACKER &&
            toCol + 2 < BOARD_SIZE &&
            (board[toRow][toCol + 2] == CellState::DEFENDER || board[toRow][toCol + 2] == CellState::KING)) {
            
            board[toRow][toCol + 1] = CellState::EMPTY;
            cout << "Captura realizada!" << endl;
        }
    }

    // Verificar si se captura a unidades defensoras o rey
    if (piece == CellState::ATTACKER) {
        // Verificar fichas adyacentes
        if (toCol - 1 >= 0 && board[toRow][toCol - 1] == getOppositePiece(piece)) {
            if (toCol - 2 >= 0 && board[toRow][toCol - 2] == piece) {
                board[toRow][toCol - 1] = CellState::EMPTY;
                cout << "Captura realizada!" << endl;
            }
        }

        if (toCol + 1 < BOARD_SIZE && board[toRow][toCol + 1] == getOppositePiece(piece)) {
            if (toCol + 2 < BOARD_SIZE && board[toRow][toCol + 2] == piece) {
                board[toRow][toCol + 1] = CellState::EMPTY;
                cout << "Captura realizada!" << endl;
            }
        }

        if (toRow - 1 >= 0 && board[toRow - 1][toCol] == getOppositePiece(piece)) {
            if (toRow - 2 >= 0 && board[toRow - 2][toCol] == piece) {
                board[toRow - 1][toCol] = CellState::EMPTY;
                cout << "Captura realizada!" << endl;
            }
        }

        if (toRow + 1 < BOARD_SIZE && board[toRow + 1][toCol] == getOppositePiece(piece)) {
            if (toRow + 2 < BOARD_SIZE && board[toRow + 2][toCol] == piece) {
                board[toRow + 1][toCol] = CellState::EMPTY;
                cout << "Captura realizada!" << endl;
            }
        }
        
        // Verificar si se captura al rey
        // Verificar si el rey se encuentra en la posición (5,5) y está rodeado por atacantes en los 4 lados
        if (kingPosition.first == 5 && kingPosition.second == 5 && 
            board[4][5] == CellState::ATTACKER && board[6][5] == CellState::ATTACKER &&
            board[5][4] == CellState::ATTACKER && board[5][6] == CellState::ATTACKER) {
            board[kingPosition.first][kingPosition.second] = CellState::EMPTY;  // Capturar al rey
        }
        // Verificar si el rey está rodeado horizontalmente
        else if (!(kingPosition.first == 5 && kingPosition.second == 5) && 
            kingPosition.second - 1 >= 0 &&
            kingPosition.second + 1 < BOARD_SIZE &&
            board[kingPosition.first][kingPosition.second - 1] == CellState::ATTACKER &&
            board[kingPosition.first][kingPosition.second + 1] == CellState::ATTACKER) {

            board[kingPosition.first][kingPosition.second] = CellState::EMPTY;  // Capturar al rey
        }
        // Verificar si el rey está rodeado verticalmente
        else if (!(kingPosition.first == 5 && kingPosition.second == 5) &&
            kingPosition.first - 1 >= 0 &&
            kingPosition.first + 1 < BOARD_SIZE &&
            board[kingPosition.first - 1][kingPosition.second] == CellState::ATTACKER &&
            board[kingPosition.first + 1][kingPosition.second] == CellState::ATTACKER) {

            board[kingPosition.first][kingPosition.second] = CellState::EMPTY;  // Capturar al rey
        }
    }
}

bool isKingEscaped() {
    int kingRow = kingPosition.first;
    int kingCol = kingPosition.second;

    if ((kingRow == 0 || kingRow == BOARD_SIZE - 1) && (kingCol == 0 || kingCol == BOARD_SIZE - 1))
        return true;

    return false;
}

bool isKingCaptured() {
    // Verificar si el rey ha sido capturado por los atacantes
    if (board[kingPosition.first][kingPosition.second] == CellState::EMPTY) {
        return true;
    }

    return false;
}

int main() {
    initializeBoard();
    displayBoard();

    int currentPlayer = 0;

    while (true) {
        int fromRow, fromCol, toRow, toCol;

        if (currentPlayer == 0) {
            cout << "Turno del atacante (A)." << endl;
        } else {
            cout << "Turno del defensor (D)." << endl;
        }

        cout << "Ingresa las coordenadas de la ficha que deseas mover (fila columna): ";
        cin >> fromRow >> fromCol;

        if (board[fromRow][fromCol] == CellState::EMPTY || board[fromRow][fromCol] == CellState::VALID) {
            cout << "¡No hay ficha válida en la posición seleccionada! Inténtalo de nuevo." << endl;
            continue;
        }

        if (currentPlayer == 0 && board[fromRow][fromCol] != CellState::ATTACKER) {
            cout << "¡No puedes mover una ficha que no sea de atacante! Inténtalo de nuevo." << endl;
            continue;
        }

        if (currentPlayer == 1 && board[fromRow][fromCol] != CellState::DEFENDER && board[fromRow][fromCol] != CellState::KING) {
            cout << "¡No puedes mover una ficha que no sea de defensor o rey! Inténtalo de nuevo." << endl;
            continue;
        }

        highlightValidMoves(fromRow, fromCol);
        displayBoard();

        cout << "Ingresa las coordenadas a las que deseas mover la ficha (fila columna): ";
        cin >> toRow >> toCol;

        if (board[toRow][toCol] != CellState::VALID) {
            cout << "¡Movimiento inválido! Inténtalo de nuevo." << endl;
            restoreBoard();
            continue;
        }

        movePiece(fromRow, fromCol, toRow, toCol);
        restoreBoard();
        displayBoard();

        if (isKingEscaped()) {
            cout << "¡El rey ha escapado! Los defensores ganan." << endl;
            break;
        }

        if (isKingCaptured()) {
            cout << "¡El rey ha sido capturado! Los atacantes ganan." << endl;
            break;
        }

        currentPlayer = 1 - currentPlayer;
    }

    return 0;
}
