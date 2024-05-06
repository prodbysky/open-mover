#version 460 core

in vec2 outTextureCoordinate;

uniform sampler2D uTexture;

out vec4 oColor;

void main() {
    oColor = texture(uTexture, outTextureCoordinate);    
}
