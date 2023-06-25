#version 330 core

in vec3 our_uv;
out vec4 color;

uniform samplerCube skybox;
uniform float lowerLimit = 0.0;
uniform float upperLimit = 0.1;
uniform vec3 fogColor;

void main()
{
	float factor = (our_uv.y - lowerLimit) / (upperLimit - lowerLimit);
	factor = clamp(factor, 0.6, 1.0);
  color = texture(skybox, our_uv);
	color = mix(vec4(fogColor, 1.0), color, factor);
}
