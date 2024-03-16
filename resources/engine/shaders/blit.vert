#version 3.3

in vec2 aTexCoord; 
in vec2 aPosition;

out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPosition, 1, 1);
    TexCoord = aTexCoord;
}