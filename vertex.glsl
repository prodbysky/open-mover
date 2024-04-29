#version 330 core

layout (location = 0) in vec3 lPos;

uniform mat4 uProjection;
uniform mat4 uView;
uniform vec3 uColor;

out vec3 outColor;

void main() {
    gl_Position = uProjection * uView * vec4(lPos, 1.0);
    outColor = uColor;
}
