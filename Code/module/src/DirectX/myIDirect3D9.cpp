#include <stdafx.h>

#pragma unmanaged

myIDirect3D9* myIDirect3D9::instance = nullptr;

myIDirect3D9::myIDirect3D9(IDirect3D9 *pOriginal)
{
    mIDirect3D9 = pOriginal;
}

myIDirect3D9::~myIDirect3D9(void)
{
}

HRESULT  __stdcall myIDirect3D9::QueryInterface(REFIID riid, void** ppvObj)
{
	*ppvObj = NULL;

	HRESULT hRes = mIDirect3D9->QueryInterface(riid, ppvObj);

	if (hRes == NOERROR)
		*ppvObj = this;

	return hRes;
}

ULONG __stdcall myIDirect3D9::AddRef(void)
{
	return(mIDirect3D9->AddRef());
}

ULONG __stdcall myIDirect3D9::Release(void)
{
	ULONG count = mIDirect3D9->Release();

	if (count == 0)
	{
		myIDirect3D9::instance = NULL;
		delete(this);
	}

	return(count);
}

HRESULT __stdcall myIDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
	return(mIDirect3D9->RegisterSoftwareDevice(pInitializeFunction));
}

UINT __stdcall myIDirect3D9::GetAdapterCount(void)
{
	return(mIDirect3D9->GetAdapterCount());
}

HRESULT __stdcall myIDirect3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
	return(mIDirect3D9->GetAdapterIdentifier(Adapter, Flags, pIdentifier));
}

UINT __stdcall myIDirect3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
	return(mIDirect3D9->GetAdapterModeCount(Adapter, Format));
}

HRESULT __stdcall myIDirect3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
	return(mIDirect3D9->EnumAdapterModes(Adapter, Format, Mode, pMode));
}

HRESULT __stdcall myIDirect3D9::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
	return(mIDirect3D9->GetAdapterDisplayMode(Adapter, pMode));
}

HRESULT __stdcall myIDirect3D9::CheckDeviceType(UINT iAdapter, D3DDEVTYPE DevType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
	return(mIDirect3D9->CheckDeviceType(iAdapter, DevType, DisplayFormat, BackBufferFormat, bWindowed));
}

HRESULT __stdcall myIDirect3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
	return(mIDirect3D9->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat));
}

HRESULT __stdcall myIDirect3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
	return(mIDirect3D9->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels));
}

HRESULT __stdcall myIDirect3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
	return(mIDirect3D9->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat));
}

HRESULT __stdcall myIDirect3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
	return(mIDirect3D9->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat));
}

HRESULT __stdcall myIDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
	return(mIDirect3D9->GetDeviceCaps(Adapter, DeviceType, pCaps));
}

HMONITOR __stdcall myIDirect3D9::GetAdapterMonitor(UINT Adapter)
{
	return(mIDirect3D9->GetAdapterMonitor(Adapter));
}

HRESULT __stdcall myIDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
	HRESULT hres = mIDirect3D9->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);

	myIDirect3DDevice9::instance = new myIDirect3DDevice9(*ppReturnedDeviceInterface);

	*ppReturnedDeviceInterface = myIDirect3DDevice9::instance;

	return(hres);
}