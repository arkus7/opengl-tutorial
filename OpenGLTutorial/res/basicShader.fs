#version 120

uniform sampler2D diffuse;

void main() {
    gl_FragColor = texture2D(diffuse, vec2(0.0, 0.0));
    //vec4(1.0, 0.0, 0.0, 1.0);
}