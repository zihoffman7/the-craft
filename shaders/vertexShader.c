#ifdef GL_FRAGMENT_PRECISION_HIGH
  precision highp float;
#else
  precision mediump float;
#endif

varying float vShadow;
uniform vec3 skyColor;
uniform sampler2D uSampler;
uniform float uTime;
uniform float uDist;
uniform vec3 uPos;
varying vec2 vTexture;
varying float vFog;

void main(void) {
  vec4 color = texture2D(uSampler, vTexture);
  if (color.a != 1.0) {
    color.a = mix(color.a, 0.0, vFog);
  }
  color = vec4(mix(color.rgb * vShadow / 16.0, (uPos.y < 40.0 ? skyColor/40.0 : skyColor) , vFog), color.a);
  gl_FragColor = color;
  if (gl_FragColor.a == 0.0) {
    discard;
  }
}
