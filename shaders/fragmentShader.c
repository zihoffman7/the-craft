varying float vShadow;
attribute vec3 aVertex;
attribute vec2 aTexture;
attribute float aShadow;
attribute float aSkylight;
varying vec2 vTexture;
uniform vec4 uColor;
uniform mat4 uView;
uniform mat4 uProjection;
uniform bool uEdge;
uniform float uTime;
uniform float uDist;
uniform float aBlocklight;
uniform vec3 uPos;
varying float vFog;
uniform vec3 skyColor;
float dUp = (uPos.y < 90.0) ? 0.0 : (uPos.y - 90.0) / 200.0;
float unDist;

void main(void) {
  unDist = ((uPos.y < 50.0) ? ((uPos.y <= 26.0) ? 20.0 + uDist * (26.0-25.0)/25.0 : (20.0 + uDist * (uPos.y-25.0)/25.0)) : uDist);
  vTexture = aTexture;
  vShadow = (uTime + 1.0) * aShadow * max(aBlocklight / 16.0, min(aSkylight / 16.0 * uTime * 0.9 + 0.1, 1.0));
  float range = max(unDist / 5.0, 2.0);
  vFog = clamp((length(uPos.xz - aVertex.xz) - unDist + range) / range, dUp, 1.0);
  gl_Position = uView * vec4(aVertex, 1.0);
}
