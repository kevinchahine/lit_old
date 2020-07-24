// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIT_EXPORTS
#define LIT_API __declspec(dllexport)
#else
#define LIT_API __declspec(dllimport)
#endif

// This class is exported from the dll
//class LIT_API Clit {
//public:
//	Clit(void);
//	// TODO: add your methods here.
//};
//
//extern LIT_API int nlit;
//
//LIT_API int fnlit(void);
//
//// This is an example of an exported variable
//LIT_API int nlit=0;
//
//// This is an example of an exported function.
//LIT_API int fnlit(void)
//{
//    return 0;
//}
//
//// This is the constructor of a class that has been exported.
//Clit::Clit()
//{
//    return;
//}
