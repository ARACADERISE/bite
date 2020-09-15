#ifndef ERR
#define ERR
#include <stdlib.h>

#ifdef WITH_CODE

#define RaiseErrorWithCode(MSG, ERR_CODE, ...) fprintf(stderr,MSG,##__VA_ARGS__), exit(ERR_CODE)

#endif

#ifdef WITH_NO_CODE

#define RaiseError(MSG, ...) fprintf(stderr, MSG, ##__VA_ARGS__), exit(EXIT_FAILURE)

#endif

#ifndef WITH_CODE
#ifndef WITH_NO_CODE

#define RaiseErrorWithCode(MSG, ERR_CODE, ...) fprintf(stderr,MSG,##__VA_ARGS__), exit(ERR_CODE)
#define RaiseError(MSG, ...) fprintf(stderr, MSG, ##__VA_ARGS__), exit(EXIT_FAILURE)

#endif
#endif

#endif