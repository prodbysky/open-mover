#version 330 core

layout (location = 0) in vec3 lPos;
layout (location = 1) in vec3 lColor;

uniform mat4 uMVP;

out vec3 outColor;

void main() {
    gl_Position = uMVP * vec4(lPos, 1.0);
    outColor = lColor;
}
