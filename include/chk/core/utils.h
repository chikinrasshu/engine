#pragma once

#define chkSizeOf(n)  sizeof(n)
#define chkCountOf(n) (chkSizeOf(n) / chkSizeOf((n)[0]))

#define chkKB(n) (1024ULL * (n))
#define chkMB(n) (1024ULL * chkKB(n))
#define chkGB(n) (1024ULL * chkMB(n))
#define chkTB(n) (1024ULL * chkGB(n))
