#include "./includes/cub3d.h"

// 0xTTRRGGBB

// T	transparency
// R	red component
// G	green component
// B	blue component

// red		0x00FF0000
// green	0x0000FF00
// blue	0x000000FF


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
//Because ints are stored from right to left, we need to bitshift each value the according amount of bits backwards. We can also do the exact opposite and retrieve integer values from a encoded TRGB integer.

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
