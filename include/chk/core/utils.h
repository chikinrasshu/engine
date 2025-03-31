#pragma once

#define SizeOf(n)  sizeof(n)
#define CountOf(n) (SizeOf(n) / SizeOf((n)[0]))

#define KiloBytes(n) (1024ULL * (n))
#define MegaBytes(n) (1024ULL * KiloBytes(n))
#define GigaBytes(n) (1024ULL * MegaBytes(n))
#define TeraBytes(n) (1024ULL * GigaBytes(n))
