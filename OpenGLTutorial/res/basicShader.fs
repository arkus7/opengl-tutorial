#version 120

varying vec2 textureCoord0;

uniform sampler2D diffuse;

void main() {
    gl_FragColor = texture2D(diffuse, textureCoord0);
    //vec4(1.0, 0.0, 0.0, 1.0);
}