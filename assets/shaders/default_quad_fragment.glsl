#version 460 core

in vec4 outColor;
out vec4 oColor;

void main() {
    if (outColor.a < 0.1) {
        discard;
    }
    oColor = outColor;
}

