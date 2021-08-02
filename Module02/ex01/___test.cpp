#include <iostream>
#include <cmath>

#define FRACT_BITS	8

int	main( void ) {

	float	f1 = 4.5f;

	std::cout << "Float: |" << f1 << "|\nFixed point one (1 << FRACT_BITS): |"
			  << (1 << FRACT_BITS) << "|\nFloat * (1 << FRACT_BITS): |"
			  << f1 * (1 << FRACT_BITS)
			  << "|\n(int)(Float * (1 << FRACT_BITS)): |"
			  << (int)(f1 * (1 << FRACT_BITS)) << "|\n";

	int	fp_val = (int)(f1 * (1 << FRACT_BITS));

	std::cout << "\n(float(x) / (1 << FRACT_BITS)): |"
			  << ((float)fp_val / (1 << FRACT_BITS)) << "|\n";

	return (0);
}
