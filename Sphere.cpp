#include "Sphere.h"

bool Sphere::hit(const Ray& r, float tMin, float tMax, hitRecord& rec) const{
	glm::vec3 oc = r.origin() - center;
	float a = glm::dot(r.direction(), r.direction());
	float half_b = glm::dot(oc, r.direction());
	float c = glm::dot(oc, oc) - radius * radius;
	float discriminant = half_b * half_b - a * c;
	if (discriminant > 0) {
		float root = sqrt(discriminant);
		float temp = (-half_b - root) / a;
		if (temp < tMax && temp > tMin) {
			rec.t = temp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center) / radius;		// dividing cheaper than sqrt
			rec.materialPtr = material;
			return true;
		}
		temp = (-half_b + root) / a;
		if (temp < tMax && temp > tMin) {
			rec.t = temp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center) / radius; 
			rec.materialPtr = material;
			return true;
		}
	}
	return false;
}