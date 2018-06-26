/* dumped in big endian order.
   use `mrbc -e` option for better performance on little endian CPU. */
#include <stdint.h>
extern const uint8_t code[];
const uint8_t
#if defined __GNUC__
__attribute__((aligned(4)))
#elif defined _MSC_VER
__declspec(align(4))
#endif
code[] = {
0x52,0x49,0x54,0x45,0x30,0x30,0x30,0x34,0xf2,0xc7,0x00,0x00,0x00,0x5c,0x4d,0x41,
0x54,0x5a,0x30,0x30,0x30,0x30,0x49,0x52,0x45,0x50,0x00,0x00,0x00,0x3e,0x30,0x30,
0x30,0x30,0x00,0x00,0x00,0x36,0x00,0x01,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x04,
0x00,0x80,0x00,0x06,0x01,0x00,0x00,0x3d,0x00,0x80,0x00,0xa0,0x00,0x00,0x00,0x4a,
0x00,0x00,0x00,0x01,0x00,0x00,0x02,0x48,0x69,0x00,0x00,0x00,0x01,0x00,0x04,0x70,
0x75,0x74,0x73,0x00,0x45,0x4e,0x44,0x00,0x00,0x00,0x00,0x08,
};
