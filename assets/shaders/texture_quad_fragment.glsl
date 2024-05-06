#version 460 core

in vec2 outTextureCoordinate;

uniform sampler2D uTexture;

out vec4 oColor;

void main() {
    if (texture(uTexture, outTextureCoordinate).a < 0.1) {
        discard;
    }
    oColor = texture(uTexture, outTextureCoordinate);    
}
