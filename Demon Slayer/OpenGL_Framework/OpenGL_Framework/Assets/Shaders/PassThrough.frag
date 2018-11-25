#version 420

uniform vec4 LightPosition;

//color
uniform vec3 LightAmbient = vec3(0.5f, 0.5f, 0.5f);
uniform vec3 LightDiffuse = vec3(0.7f, 0.7f, 0.7f);
uniform vec3 LightSpecular = vec3(0.7f, 0.7f, 0.7f);

//scalars
uniform float LightSpecularExponent = 50.0f;
uniform float Attenuation_Constant = 1.0f;
uniform float Attenuation_Linear = 0.1f;
uniform float Attenuation_Quadratic = 0.01f;

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

	vec4 textureColor = texture(uTex, texcoord);
	outColor.rgb *= textureColor.rgb;
	outColor.a *= textureColor.a;

}