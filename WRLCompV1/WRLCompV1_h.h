

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Thu Dec 27 20:54:44 2012
 */
/* Compiler settings for C:\Users\Olivier\AppData\Local\Temp\WRLCompV1.idl-0e5cd94a:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __WRLCompV1_h_h__
#define __WRLCompV1_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(__cplusplus)
#if defined(__MIDL_USE_C_ENUM)
#define MIDL_ENUM enum
#else
#define MIDL_ENUM enum class
#endif
#endif


/* Forward Declarations */ 

#ifndef ____x_ABI_CWRLCompV1_CIPerson_FWD_DEFINED__
#define ____x_ABI_CWRLCompV1_CIPerson_FWD_DEFINED__
typedef interface __x_ABI_CWRLCompV1_CIPerson __x_ABI_CWRLCompV1_CIPerson;

#ifdef __cplusplus
namespace ABI {
    namespace WRLCompV1 {
        interface IPerson;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CWRLCompV1_CIPerson_FWD_DEFINED__ */


#ifndef ____x_ABI_CWRLCompV1_CIAddress_FWD_DEFINED__
#define ____x_ABI_CWRLCompV1_CIAddress_FWD_DEFINED__
typedef interface __x_ABI_CWRLCompV1_CIAddress __x_ABI_CWRLCompV1_CIAddress;

#ifdef __cplusplus
namespace ABI {
    namespace WRLCompV1 {
        interface IAddress;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CWRLCompV1_CIAddress_FWD_DEFINED__ */


#ifndef ____x_ABI_CWRLCompV1_CISaveable_FWD_DEFINED__
#define ____x_ABI_CWRLCompV1_CISaveable_FWD_DEFINED__
typedef interface __x_ABI_CWRLCompV1_CISaveable __x_ABI_CWRLCompV1_CISaveable;

#ifdef __cplusplus
namespace ABI {
    namespace WRLCompV1 {
        interface ISaveable;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CWRLCompV1_CISaveable_FWD_DEFINED__ */


#ifndef ____x_ABI_CWRLCompV1_CICitizen_FWD_DEFINED__
#define ____x_ABI_CWRLCompV1_CICitizen_FWD_DEFINED__
typedef interface __x_ABI_CWRLCompV1_CICitizen __x_ABI_CWRLCompV1_CICitizen;

#ifdef __cplusplus
namespace ABI {
    namespace WRLCompV1 {
        interface ICitizen;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CWRLCompV1_CICitizen_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"
#include "Windows.Foundation.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_WRLCompV1_0000_0000 */
/* [local] */ 





#ifdef __cplusplus
namespace ABI {
namespace WRLCompV1 {
class PersonClass;
} /*WRLCompV1*/
}
#endif
#ifdef __cplusplus
namespace ABI {
namespace WRLCompV1 {
class AddressClass;
} /*WRLCompV1*/
}
#endif
#ifdef __cplusplus
namespace ABI {
namespace WRLCompV1 {
class CitizenClass;
} /*WRLCompV1*/
}
#endif
#if !defined(____x_ABI_CWRLCompV1_CIPerson_INTERFACE_DEFINED__)
extern const __declspec(selectany) WCHAR InterfaceName_WRLCompV1_IPerson[] = L"WRLCompV1.IPerson";
#endif /* !defined(____x_ABI_CWRLCompV1_CIPerson_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_WRLCompV1_0000_0000 */
/* [local] */ 







extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0000_v0_0_s_ifspec;

#ifndef ____x_ABI_CWRLCompV1_CIPerson_INTERFACE_DEFINED__
#define ____x_ABI_CWRLCompV1_CIPerson_INTERFACE_DEFINED__

/* interface __x_ABI_CWRLCompV1_CIPerson */
/* [uuid][object] */ 



/* interface ABI::WRLCompV1::IPerson */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CWRLCompV1_CIPerson;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace WRLCompV1 {
            
            MIDL_INTERFACE("0d585932-fbc4-4b0a-90b5-ccf34aefd4c6")
            IPerson : public IInspectable
            {
            public:
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
                    /* [out][retval] */ HSTRING *value) = 0;
                
                virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
                    /* [in] */ HSTRING value) = 0;
                
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Surname( 
                    /* [out][retval] */ HSTRING *value) = 0;
                
                virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Surname( 
                    /* [in] */ HSTRING value) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_IPerson = __uuidof(IPerson);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CWRLCompV1_CIPersonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CWRLCompV1_CIPerson * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CWRLCompV1_CIPerson * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CWRLCompV1_CIPerson * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CWRLCompV1_CIPerson * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CWRLCompV1_CIPerson * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CWRLCompV1_CIPerson * This,
            /* [out] */ TrustLevel *trustLevel);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __x_ABI_CWRLCompV1_CIPerson * This,
            /* [out][retval] */ HSTRING *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __x_ABI_CWRLCompV1_CIPerson * This,
            /* [in] */ HSTRING value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Surname )( 
            __x_ABI_CWRLCompV1_CIPerson * This,
            /* [out][retval] */ HSTRING *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Surname )( 
            __x_ABI_CWRLCompV1_CIPerson * This,
            /* [in] */ HSTRING value);
        
        END_INTERFACE
    } __x_ABI_CWRLCompV1_CIPersonVtbl;

    interface __x_ABI_CWRLCompV1_CIPerson
    {
        CONST_VTBL struct __x_ABI_CWRLCompV1_CIPersonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CWRLCompV1_CIPerson_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CWRLCompV1_CIPerson_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CWRLCompV1_CIPerson_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CWRLCompV1_CIPerson_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CWRLCompV1_CIPerson_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CWRLCompV1_CIPerson_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CWRLCompV1_CIPerson_get_Name(This,value)	\
    ( (This)->lpVtbl -> get_Name(This,value) ) 

#define __x_ABI_CWRLCompV1_CIPerson_put_Name(This,value)	\
    ( (This)->lpVtbl -> put_Name(This,value) ) 

#define __x_ABI_CWRLCompV1_CIPerson_get_Surname(This,value)	\
    ( (This)->lpVtbl -> get_Surname(This,value) ) 

#define __x_ABI_CWRLCompV1_CIPerson_put_Surname(This,value)	\
    ( (This)->lpVtbl -> put_Surname(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CWRLCompV1_CIPerson_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_WRLCompV1_0000_0001 */
/* [local] */ 

#if !defined(____x_ABI_CWRLCompV1_CIAddress_INTERFACE_DEFINED__)
extern const __declspec(selectany) WCHAR InterfaceName_WRLCompV1_IAddress[] = L"WRLCompV1.IAddress";
#endif /* !defined(____x_ABI_CWRLCompV1_CIAddress_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_WRLCompV1_0000_0001 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0001_v0_0_s_ifspec;

#ifndef ____x_ABI_CWRLCompV1_CIAddress_INTERFACE_DEFINED__
#define ____x_ABI_CWRLCompV1_CIAddress_INTERFACE_DEFINED__

/* interface __x_ABI_CWRLCompV1_CIAddress */
/* [uuid][object] */ 



/* interface ABI::WRLCompV1::IAddress */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CWRLCompV1_CIAddress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace WRLCompV1 {
            
            MIDL_INTERFACE("497783FC-D66D-4DF6-AAFC-C4D879AB22F1")
            IAddress : public IInspectable
            {
            public:
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Street( 
                    /* [out][retval] */ HSTRING *value) = 0;
                
                virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Street( 
                    /* [in] */ HSTRING value) = 0;
                
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_City( 
                    /* [out][retval] */ HSTRING *value) = 0;
                
                virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_City( 
                    /* [in] */ HSTRING value) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_IAddress = __uuidof(IAddress);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CWRLCompV1_CIAddressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CWRLCompV1_CIAddress * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CWRLCompV1_CIAddress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CWRLCompV1_CIAddress * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CWRLCompV1_CIAddress * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CWRLCompV1_CIAddress * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CWRLCompV1_CIAddress * This,
            /* [out] */ TrustLevel *trustLevel);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Street )( 
            __x_ABI_CWRLCompV1_CIAddress * This,
            /* [out][retval] */ HSTRING *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Street )( 
            __x_ABI_CWRLCompV1_CIAddress * This,
            /* [in] */ HSTRING value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_City )( 
            __x_ABI_CWRLCompV1_CIAddress * This,
            /* [out][retval] */ HSTRING *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_City )( 
            __x_ABI_CWRLCompV1_CIAddress * This,
            /* [in] */ HSTRING value);
        
        END_INTERFACE
    } __x_ABI_CWRLCompV1_CIAddressVtbl;

    interface __x_ABI_CWRLCompV1_CIAddress
    {
        CONST_VTBL struct __x_ABI_CWRLCompV1_CIAddressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CWRLCompV1_CIAddress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CWRLCompV1_CIAddress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CWRLCompV1_CIAddress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CWRLCompV1_CIAddress_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CWRLCompV1_CIAddress_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CWRLCompV1_CIAddress_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CWRLCompV1_CIAddress_get_Street(This,value)	\
    ( (This)->lpVtbl -> get_Street(This,value) ) 

#define __x_ABI_CWRLCompV1_CIAddress_put_Street(This,value)	\
    ( (This)->lpVtbl -> put_Street(This,value) ) 

#define __x_ABI_CWRLCompV1_CIAddress_get_City(This,value)	\
    ( (This)->lpVtbl -> get_City(This,value) ) 

#define __x_ABI_CWRLCompV1_CIAddress_put_City(This,value)	\
    ( (This)->lpVtbl -> put_City(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CWRLCompV1_CIAddress_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_WRLCompV1_0000_0002 */
/* [local] */ 

#if !defined(____x_ABI_CWRLCompV1_CISaveable_INTERFACE_DEFINED__)
extern const __declspec(selectany) WCHAR InterfaceName_WRLCompV1_ISaveable[] = L"WRLCompV1.ISaveable";
#endif /* !defined(____x_ABI_CWRLCompV1_CISaveable_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_WRLCompV1_0000_0002 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0002_v0_0_s_ifspec;

#ifndef ____x_ABI_CWRLCompV1_CISaveable_INTERFACE_DEFINED__
#define ____x_ABI_CWRLCompV1_CISaveable_INTERFACE_DEFINED__

/* interface __x_ABI_CWRLCompV1_CISaveable */
/* [uuid][object] */ 



/* interface ABI::WRLCompV1::ISaveable */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CWRLCompV1_CISaveable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace WRLCompV1 {
            
            MIDL_INTERFACE("C3F9CEA3-B897-4A79-BF6C-02B5DF4DB77D")
            ISaveable : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE CanSave( 
                    /* [out][retval] */ boolean *value) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_ISaveable = __uuidof(ISaveable);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CWRLCompV1_CISaveableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CWRLCompV1_CISaveable * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CWRLCompV1_CISaveable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CWRLCompV1_CISaveable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CWRLCompV1_CISaveable * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CWRLCompV1_CISaveable * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CWRLCompV1_CISaveable * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *CanSave )( 
            __x_ABI_CWRLCompV1_CISaveable * This,
            /* [out][retval] */ boolean *value);
        
        END_INTERFACE
    } __x_ABI_CWRLCompV1_CISaveableVtbl;

    interface __x_ABI_CWRLCompV1_CISaveable
    {
        CONST_VTBL struct __x_ABI_CWRLCompV1_CISaveableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CWRLCompV1_CISaveable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CWRLCompV1_CISaveable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CWRLCompV1_CISaveable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CWRLCompV1_CISaveable_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CWRLCompV1_CISaveable_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CWRLCompV1_CISaveable_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CWRLCompV1_CISaveable_CanSave(This,value)	\
    ( (This)->lpVtbl -> CanSave(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CWRLCompV1_CISaveable_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_WRLCompV1_0000_0003 */
/* [local] */ 

#if !defined(____x_ABI_CWRLCompV1_CICitizen_INTERFACE_DEFINED__)
extern const __declspec(selectany) WCHAR InterfaceName_WRLCompV1_ICitizen[] = L"WRLCompV1.ICitizen";
#endif /* !defined(____x_ABI_CWRLCompV1_CICitizen_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_WRLCompV1_0000_0003 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0003_v0_0_s_ifspec;

#ifndef ____x_ABI_CWRLCompV1_CICitizen_INTERFACE_DEFINED__
#define ____x_ABI_CWRLCompV1_CICitizen_INTERFACE_DEFINED__

/* interface __x_ABI_CWRLCompV1_CICitizen */
/* [uuid][object] */ 



/* interface ABI::WRLCompV1::ICitizen */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CWRLCompV1_CICitizen;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace WRLCompV1 {
            
            MIDL_INTERFACE("863571FC-4CBB-47E8-8BD3-2709D5CB7D0D")
            ICitizen : public IInspectable
            {
            public:
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
                    /* [out][retval] */ HSTRING *value) = 0;
                
                virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
                    /* [in] */ HSTRING value) = 0;
                
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Surname( 
                    /* [out][retval] */ HSTRING *value) = 0;
                
                virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Surname( 
                    /* [in] */ HSTRING value) = 0;
                
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
                    /* [out][retval] */ ABI::WRLCompV1::IAddress **value) = 0;
                
                virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Address( 
                    /* [in] */ ABI::WRLCompV1::IAddress *value) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_ICitizen = __uuidof(ICitizen);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CWRLCompV1_CICitizenVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CWRLCompV1_CICitizen * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CWRLCompV1_CICitizen * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [out] */ TrustLevel *trustLevel);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [out][retval] */ HSTRING *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [in] */ HSTRING value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Surname )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [out][retval] */ HSTRING *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Surname )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [in] */ HSTRING value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [out][retval] */ __x_ABI_CWRLCompV1_CIAddress **value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Address )( 
            __x_ABI_CWRLCompV1_CICitizen * This,
            /* [in] */ __x_ABI_CWRLCompV1_CIAddress *value);
        
        END_INTERFACE
    } __x_ABI_CWRLCompV1_CICitizenVtbl;

    interface __x_ABI_CWRLCompV1_CICitizen
    {
        CONST_VTBL struct __x_ABI_CWRLCompV1_CICitizenVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CWRLCompV1_CICitizen_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CWRLCompV1_CICitizen_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CWRLCompV1_CICitizen_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CWRLCompV1_CICitizen_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CWRLCompV1_CICitizen_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CWRLCompV1_CICitizen_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CWRLCompV1_CICitizen_get_Name(This,value)	\
    ( (This)->lpVtbl -> get_Name(This,value) ) 

#define __x_ABI_CWRLCompV1_CICitizen_put_Name(This,value)	\
    ( (This)->lpVtbl -> put_Name(This,value) ) 

#define __x_ABI_CWRLCompV1_CICitizen_get_Surname(This,value)	\
    ( (This)->lpVtbl -> get_Surname(This,value) ) 

#define __x_ABI_CWRLCompV1_CICitizen_put_Surname(This,value)	\
    ( (This)->lpVtbl -> put_Surname(This,value) ) 

#define __x_ABI_CWRLCompV1_CICitizen_get_Address(This,value)	\
    ( (This)->lpVtbl -> get_Address(This,value) ) 

#define __x_ABI_CWRLCompV1_CICitizen_put_Address(This,value)	\
    ( (This)->lpVtbl -> put_Address(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CWRLCompV1_CICitizen_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_WRLCompV1_0000_0004 */
/* [local] */ 

#ifndef RUNTIMECLASS_WRLCompV1_PersonClass_DEFINED
#define RUNTIMECLASS_WRLCompV1_PersonClass_DEFINED
extern const __declspec(selectany) WCHAR RuntimeClass_WRLCompV1_PersonClass[] = L"WRLCompV1.PersonClass";
#endif
#ifndef RUNTIMECLASS_WRLCompV1_AddressClass_DEFINED
#define RUNTIMECLASS_WRLCompV1_AddressClass_DEFINED
extern const __declspec(selectany) WCHAR RuntimeClass_WRLCompV1_AddressClass[] = L"WRLCompV1.AddressClass";
#endif
#ifndef RUNTIMECLASS_WRLCompV1_CitizenClass_DEFINED
#define RUNTIMECLASS_WRLCompV1_CitizenClass_DEFINED
extern const __declspec(selectany) WCHAR RuntimeClass_WRLCompV1_CitizenClass[] = L"WRLCompV1.CitizenClass";
#endif


/* interface __MIDL_itf_WRLCompV1_0000_0004 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WRLCompV1_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HSTRING_UserSize(     unsigned long *, unsigned long            , HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserMarshal(  unsigned long *, unsigned char *, HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserUnmarshal(unsigned long *, unsigned char *, HSTRING * ); 
void                      __RPC_USER  HSTRING_UserFree(     unsigned long *, HSTRING * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


