#version 3.3

in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D blitTexture;

void main()
{
    FragColor = texture(blitTexture, TexCoord);
}