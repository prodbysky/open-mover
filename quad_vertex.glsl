#version 330 core

layout (location = 0) in vec3 lPos;
layout (location = 1) in vec2 lTextureCoordinate;

uniform mat4 uProjection;
uniform mat4 uModel;
uniform vec3 uColor;

out vec3 outColor;
out vec2 outTextureCoordinate;

void main() {
    gl_Position = uProjection * uModel * vec4(lPos, 1.0);
    outColor = uColor;
    outTextureCoordinate = lTextureCoordinate;
}
