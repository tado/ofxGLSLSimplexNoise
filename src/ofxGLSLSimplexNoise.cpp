#include "ofxGLSLSimplexNoise.h"

ofxGLSLSimplexNoise::ofxGLSLSimplexNoise() {
    frag = STRINGIFY
    (
     
     float zero_one(float n) {
         return (n + 1.0) / 2.0;
     }
     
     float minus_plus_one(float n) {
         return (n - 0.5) * 2.0;
     }
     vec3 mod289(vec3 x) {
         return x - floor(x * (1.0 / 289.0)) * 289.0;
     }
     
     vec4 mod289(vec4 x) {
         return x - floor(x * (1.0 / 289.0)) * 289.0;
     }
     
     vec4 permute(vec4 x) {
         return mod289(((x*34.0) + 1.0)*x);
     }
     
     vec4 taylorInvSqrt(vec4 r) {
         return 1.79284291400159 - 0.85373472095314 * r;
     }
     
     float snoise(vec3 v) {
         const vec2  C = vec2(1.0 / 6.0, 1.0 / 3.0);
         const vec4  D = vec4(0.0, 0.5, 1.0, 2.0);
         
         vec3 i = floor(v + dot(v, C.yyy));
         vec3 x0 = v - i + dot(i, C.xxx);
         
         vec3 g = step(x0.yzx, x0.xyz);
         vec3 l = 1.0 - g;
         vec3 i1 = min(g.xyz, l.zxy);
         vec3 i2 = max(g.xyz, l.zxy);
         
         vec3 x1 = x0 - i1 + C.xxx;
         vec3 x2 = x0 - i2 + C.yyy;
         vec3 x3 = x0 - D.yyy;
         
         i = mod289(i);
         vec4 p = permute(permute(permute(i.z + vec4(0.0, i1.z, i2.z, 1.0)) + i.y + vec4(0.0, i1.y, i2.y, 1.0)) + i.x + vec4(0.0, i1.x, i2.x, 1.0));
         
         float n_ = 0.142857142857;
         vec3  ns = n_ * D.wyz - D.xzx;
         
         vec4 j = p - 49.0 * floor(p * ns.z * ns.z);
         
         vec4 x_ = floor(j * ns.z);
         vec4 y_ = floor(j - 7.0 * x_);
         
         vec4 x = x_ *ns.x + ns.yyyy;
         vec4 y = y_ *ns.x + ns.yyyy;
         vec4 h = 1.0 - abs(x) - abs(y);
         
         vec4 b0 = vec4(x.xy, y.xy);
         vec4 b1 = vec4(x.zw, y.zw);
         
         vec4 s0 = floor(b0)*2.0 + 1.0;
         vec4 s1 = floor(b1)*2.0 + 1.0;
         vec4 sh = -step(h, vec4(0.0));
         
         vec4 a0 = b0.xzyw + s0.xzyw*sh.xxyy;
         vec4 a1 = b1.xzyw + s1.xzyw*sh.zzww;
         
         vec3 p0 = vec3(a0.xy, h.x);
         vec3 p1 = vec3(a0.zw, h.y);
         vec3 p2 = vec3(a1.xy, h.z);
         vec3 p3 = vec3(a1.zw, h.w);
         
         vec4 norm = taylorInvSqrt(vec4(dot(p0, p0), dot(p1, p1), dot(p2, p2), dot(p3, p3)));
         p0 *= norm.x;
         p1 *= norm.y;
         p2 *= norm.z;
         p3 *= norm.w;
         
         vec4 m = max(0.6 - vec4(dot(x0, x0), dot(x1, x1), dot(x2, x2), dot(x3, x3)), 0.0);
         m = m * m;
         return 42.0 * dot(m*m, vec4(dot(p0, x0), dot(p1, x1),
                                     dot(p2, x2), dot(p3, x3)));
     }
     
     uniform float time;
     uniform vec2 resolution;
     uniform vec2 freqR;
     uniform vec2 freqG;
     uniform vec2 freqB;
     uniform vec2 shiftR;
     uniform vec2 shiftG;
     uniform vec2 shiftB;
     uniform vec3 colorR;
     uniform vec3 colorG;
     uniform vec3 colorB;
     uniform vec3 speed;
     uniform vec3 mul;
     uniform vec3 add;
     uniform float alpha;
     varying vec3 v_texCoord3D;
     
     void main(void) {
         mat3 matColor = mat3(colorR, colorG, colorB);
         
         vec3 uv = v_texCoord3D * 50.0;
         float w = 1.0;
         float h = 1.0;
         
         float r = mul.r * zero_one(snoise(vec3(uv.x * w * freqR.x, uv.y * h * freqR.y, speed.r * time)) + add.r);
         float g = mul.g * zero_one(snoise(vec3(uv.x * w * freqG.x, uv.y * h * freqG.y, speed.g * time)) + add.g);
         float b = mul.b * zero_one(snoise(vec3(uv.x * w * freqB.x, uv.y * h * freqB.y, speed.b * time)) + add.b);
         
         vec3 rgb = vec3(r, g, b);
         gl_FragColor = vec4((matColor * rgb), alpha);
     }
     );
    
    vert = STRINGIFY
    (
     uniform float time;
     varying vec3 v_texCoord3D;
     
     void main(void) {
         gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
         v_texCoord3D = gl_Vertex.xyz;
     }
     );
    
    if (frag.empty() == false) {
        shader.setupShaderFromSource(GL_FRAGMENT_SHADER, frag);
    }
    if (vert.empty() == false) {
        shader.setupShaderFromSource(GL_VERTEX_SHADER, vert);
    }
    
    shader.linkProgram();
    
    freqR.set(0.5, 0.5);
    freqG.set(0.4, 0.4);
    freqB.set(0.2, 1.0);
    
    colorR.set(0.8, 0.4, 0.2);
    colorG.set(0.2, 0.8, 0.4);
    colorB.set(0.4, 0.2, 0.8);
    
    mul.set(0.2, 1.0, 1.0);
    add.set(0.0, 0.0, 0.0);
    speed.set(0.2, 0.3, 0.4);
    
    alpha = 1.0;
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
}

void ofxGLSLSimplexNoise::draw() {
    fbo.begin();
    ofClear(0);
    fbo.end();
    fbo.begin();
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform2f("freqR", freqR.x, freqR.y);
    shader.setUniform2f("freqG", freqG.x, freqG.y);
    shader.setUniform2f("freqB", freqB.x, freqB.y);
    
    shader.setUniform3f("colorR", colorR.x, colorR.y, colorR.z);
    shader.setUniform3f("colorG", colorG.x, colorG.y, colorG.z);
    shader.setUniform3f("colorB", colorB.x, colorB.y, colorB.z);
    
    //shader.setUniform2f("shiftR", shiftR.x, shiftR.y);
    //shader.setUniform2f("shiftG", shiftG.x, shiftR.y);
    //shader.setUniform2f("shiftB", shiftB.x, shiftR.y);
    shader.setUniform3f("mul", mul.x, mul.y, mul.z);
    shader.setUniform3f("add", add.x, add.y, add.z);
    shader.setUniform3f("speed", speed.x, speed.y, speed.z);
    shader.setUniform1f("alpha", alpha);
    
    ofScale(ofGetWidth(), ofGetWidth());
    ofDrawRectangle(0, 0, 1.0, 1.0);
    shader.end();
    fbo.end();
    
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}
