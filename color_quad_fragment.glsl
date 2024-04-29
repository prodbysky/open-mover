#version 330 core

in vec3 outColor;
out vec4 oColor;

void main() {
    oColor = vec4(outColor, 1.0f);
}

