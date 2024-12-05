#version 330 core
out vec4 FragColor;
in vec3 color;
in vec2 tex;

uniform sampler2D Texture0;

void main()
{
   FragColor = texture(Texture0,tex);
}