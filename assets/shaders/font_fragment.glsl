#version 460 core
in vec2 outTexCoords;
out vec4 color;

uniform sampler2D uText;
uniform vec3 uColor;

void main() {    
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(uText, outTexCoords).r);
    color = vec4(uColor.rgb, texture(uText, outTexCoords).r);
}  
