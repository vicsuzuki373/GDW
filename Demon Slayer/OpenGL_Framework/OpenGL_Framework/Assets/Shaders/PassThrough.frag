#version 420

uniform vec4 LightPosition;
uniform vec4 LightPosition2;

//color
uniform vec3 LightAmbient = vec3(0.25f, 0.21f, 0.25f);
uniform vec3 LightDiffuse = vec3(0.5f, 0.3f, 0.0f);
uniform vec3 LightSpecular = vec3(0.5f, 0.3f, 0.0f);

uniform vec3 LightDiffuse2 = vec3(1.0f, 1.0f, 1.0f);
uniform vec3 LightSpecular2 = vec3(1.0f, 1.0f, 1.0f);

//scalars
uniform float LightSpecularExponent = 50.0f;
uniform float Attenuation_Constant = 1.0f;
uniform float Attenuation_Linear = 0.1f;
uniform float Attenuation_Quadratic = 0.1f;

uniform float LightSpecularExponent2 = 100.0f;
uniform float Attenuation_Constant2 = 1.0f;
uniform float Attenuation_Linear2 = 0.03f;
uniform float Attenuation_Quadratic2 = 0.003f;

uniform sampler2D uTex;

in vec2 texcoord;
in vec3 norm;
in vec3 pos;

out vec4 outColor;


void main()
{
	outColor.rbg = LightAmbient;

	// Account for rasterizer interpolating
	vec3 normal = normalize(norm);

	vec3 lightVec = LightPosition.xyz - pos;
	float dist = length(lightVec);
	vec3 lightDir = lightVec / dist;

	float NdotL = dot(normal, lightDir);

	if(NdotL > 0.0)
	{
		// The light contributes to this surface
		// Calculate attenuation (falloff)
		float attenuation = 1.0 / (Attenuation_Constant + (Attenuation_Linear * dist) + (Attenuation_Quadratic * dist * dist));

		// Calculate diffuse contribution
		outColor.rgb += LightDiffuse * NdotL * attenuation;

		// Blinn-Phong half vector
		float NdotHV = max(dot(normal, normalize(lightDir + normalize(-pos))), 0.0);

		// Calculate specular contribution
		outColor.rgb += LightSpecular * pow(NdotHV, LightSpecularExponent) * attenuation;
	}

	vec3 lightVec2 = LightPosition2.xyz - pos;
	float dist2 = length(lightVec2);
	vec3 lightDir2 = lightVec2 / dist2;
	float NdotL2 = dot(normal, lightDir2);

	if(NdotL2 > 0.0)
	{
		float attenuation2 = 1.0 / (Attenuation_Constant2 + (Attenuation_Linear2 * dist2) + (Attenuation_Quadratic2 * dist2 * dist2));
		outColor.rgb += LightDiffuse2 * NdotL2 * attenuation2;
		float NdotHV2 = max(dot(normal, normalize(lightDir2 + normalize(-pos))), 0.0);
		outColor.rgb += LightSpecular2 * pow(NdotHV2, LightSpecularExponent2) * attenuation2;
	}

	vec4 textureColor = texture(uTex, texcoord);
	outColor.rgb *= textureColor.rgb;
	outColor.a = textureColor.a;

}