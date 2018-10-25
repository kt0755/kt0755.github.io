#define _GNU_SOURCE
#include <endian.h>
#include <stdint.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

uint64_t r[1] = {0xffffffffffffffff};
void loop()
{
  long res;
  res = syscall(__NR_socket, 0xa, 6, 0);
  if (res != -1)
    r[0] = res;
  *(uint16_t*)0x20000140 = 0xa;
  *(uint16_t*)0x20000142 = htobe16(0x4e22);
  *(uint32_t*)0x20000144 = 0;
  *(uint64_t*)0x20000148 = htobe64(0);
  *(uint64_t*)0x20000150 = htobe64(1);
  *(uint32_t*)0x20000158 = 2;
  syscall(__NR_bind, r[0], 0x20000140, 0);
}

int main()
{
  syscall(__NR_mmap, 0x20000000, 0x1000000, 3, 0x32, -1, 0);
  loop();
  return 0;
}
