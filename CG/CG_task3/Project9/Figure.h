#pragma once
#include<vector>
#include"Matrix.h"

class path {
	public:
		std::vector<vec2> vertices; // ������������������ �����
		vec3 color; // ����, �������� �� ������������ RGB
		float thickness; // ������� �����
		path(std::vector<vec2> verts, vec3 col, float thickn) {
			vertices = verts;
			color = col;
			thickness = thickn;
		}
};