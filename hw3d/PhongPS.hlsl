cbuffer LightCBuf
{
    float3 lightPos;
    float3 ambient;
    float3 diffuseColour;
    float diffuseIntensity;
    float attConst;
    float attLin;
    float attQuad;
};

cbuffer ObjectVBuf
{
    float3 materialColour;
};


float4 main(float3 worldPos : Position, float3 n : Normal) : SV_TARGET
{
    const float3 vToL = lightPos - worldPos;
    const float distToL = length(vToL);
    const float3 dirToL = vToL / distToL;

    const float att = 1.0f / (attConst + distToL * attLin + attQuad * (distToL * distToL));

    const float3 diffuse = diffuseColour * diffuseIntensity * att * max(0.0f, dot(dirToL, n));

    return float4(saturate((diffuse + ambient) * materialColour), 1.0f);

}