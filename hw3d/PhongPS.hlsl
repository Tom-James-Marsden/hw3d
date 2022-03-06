cbuffer LightCBuf
{
    float3 lightPos;
};

static const float3 materialColour = { 0.7f, 0.7f, 0.9f };
static const float3 ambient = { 0.15f, 0.15f, 0.15f };
static const float3 diffuseColour = { 1.0f, 1.0f, 1.0f };
static const float diffuseIntensity = 1.0f;
static const float attConst = 1.0f;
static const float attLin = 1.0f;
static const float attQuad = 1.0f;


float4 main(float3 worldPos : Position, float3 n : Normal) : SV_TARGET
{
    const float3 vToL = lightPos - worldPos;
    const float distToL = length(vToL);
    const float3 dirToL = vToL / distToL;

    const float att = 1.0f / (attConst + distToL * attLin + attQuad * (distToL * distToL));

    const float3 diffuse = diffuseColour * diffuseIntensity * att * max(0.0f, dot(dirToL, n));

    return float4(saturate(diffuse + ambient)/* + materialColour*/, 1.0f);

}