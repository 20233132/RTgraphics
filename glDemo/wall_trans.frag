#version 410

uniform sampler2D texture;

in SimplePacket {

	vec2 texCoord;

} inputFragment;


layout (location=0) out vec4 fragColour;

void main(void) {

	fragColour = vec4(0.0f,0.0f,0.0f,0.5f);
}
