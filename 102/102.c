/*
Problem 102

Three distinct points are plotted at random on a Cartesian plane, for which -1000 ≤ x, y ≤ 1000, such that a triangle is formed.

Consider the following two triangles:

A(-340,495), B(-153,-910), C(835,-947)

	X(-175,41), Y(-421,-714), Z(574,-645)

	It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.

	Using triangles.txt (right click and 'Save Link/Target As...'), a 27K text file containing the co-ordinates of one thousand "random" triangles, find the number of triangles for which the interior contains the origin.

	NOTE: The first two examples in the file represent the triangles in the example given above.

*/

#include <stdio.h>
#include "triangles.h"

#define X (pt->x)
#define Y (pt->y)

#define X1 (tri->pt1.x)
#define Y1 (tri->pt1.y)

#define X2 (tri->pt2.x)
#define Y2 (tri->pt2.y)

#define X3 (tri->pt3.x)
#define Y3 (tri->pt3.y)

#define PT1 (tri->pt1)
#define PT2 (tri->pt2)
#define PT3 (tri->pt3)

inline int tri_area (struct triangle *tri) {
	return ((X1 * (Y2 - Y3)) + (X2 * (Y3 - Y1)) + (X3 * (Y1 - Y2)));
}

unsigned char is_inside (struct point pt, struct triangle *tri) {
	int ar1, ar2, ar3, total;
	struct triangle temp;

	total = tri_area (tri);
	if (total < 0) total *= -1;

	temp.pt1 = pt;
	temp.pt2 = tri->pt2;
	temp.pt3 = tri->pt3;
	ar1 = tri_area (&temp);
	if (ar1 < 0) ar1 *= -1;

	temp.pt1 = tri->pt1;
	temp.pt2 = pt;
	temp.pt3 = tri->pt3;
	ar2 = tri_area (&temp);
	if (ar2 < 0) ar2 *= -1;

	temp.pt1 = tri->pt1;
	temp.pt2 = tri->pt2;
	temp.pt3 = pt;
	ar3 = tri_area (&temp);
	if (ar3 < 0) ar3 *= -1;

	return ((ar1 + ar2 + ar3) <= total);
}

int main () {
	int i, count;
	struct point origin = {0,0};

	for (count = 0, i = 0; i < NO_TRI; i++)
		if (is_inside (origin, &list[i])) count++;

	printf ("%d\n", count);
	return 0;
}
