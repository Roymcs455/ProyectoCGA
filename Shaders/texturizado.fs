#version 330 core

out vec4 color;

in vec2 our_uv;

uniform sampler2D ourTexture;

void main()
{
	vec4 textureColor = texture(ourTexture, our_uv);
	if (textureColor.a <0.1)
		discard;
	color = textureColor;
}