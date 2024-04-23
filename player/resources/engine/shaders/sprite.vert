#version 330 core


layout(location = 0) in vec2 aPosition;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat3 spriteMatrix;
uniform mat3 viewMatrix;
uniform mat3 projectionMatrix;
uniform mat3 texCoordsTransform;

void main()
{
    gl_Position = vec4((projectionMatrix * viewMatrix * spriteMatrix * vec3(aPosition.xy, 1)).xy, 1, 1);
    TexCoord = (texCoordsTransform * vec3(aTexCoord.xy, 1)).xy;
}