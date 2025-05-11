#include "includes.h"
#include "AltPoint/Drawing.h"
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}


	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Always);
	if (ImGui::Begin("##mainthing", nullptr, winflags))
	{
		ImGui::Text("Pixel Strike Base By 0SD47");
		ImGui::Separator();
		ImGui::Spacing();
		ImGui::Checkbox("No Recoil", &norecoil);

		ImGui::Spacing();

		ImGui::Checkbox("Mass Loop Reload", &MassLoopReload);

		ImGui::Spacing();

		ImGui::Checkbox("Speed Test", &SpeedTest);
		ImGui::SameLine();
		ImGui::Text("[Bannable]");
		ImGui::Spacing();

		ImGui::Checkbox("Jump Boost", &JumpBoost);
		ImGui::Spacing();

		ImGui::Checkbox("Fly", &Fly);

		ImGui::Spacing();

		ImGui::Checkbox("Infinite Jump", &InfiniteJump);

		ImGui::Spacing();

		ImGui::Checkbox("Rapid Fire", &RapidFire);

		ImGui::Spacing();

		ImGui::Checkbox("Set Weapon", &SetWeapon);

		ImGui::Spacing();

		ImGui::Spacing();

		if (SpeedTest)
		{
			ImGui::SliderFloat("Speed", &SpeedTestSlider, 0.f, 120.f);
		}


		if (ImGui::Button("Get Reward"))
		{
			GetReward = true;
		}
		else
			GetReward = false;


		ImGui::End();
	}
	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}


bool Hooks()
{
	std::cout << "Hooks initialization starting..." << std::endl;
	try {
		hookz();
		std::cout << "Hooks initialization successfully." << std::endl;
	}
	catch (const std::exception& idk) {
		std::cerr << "Error during hooks initialization: " << idk.what() << std::endl;
		return false;
	}
	return true;
}
uintptr_t Base = (uintptr_t)GetModuleHandleW(L"GameAssembly.dll");
DWORD pid = GetCurrentProcessId();


void safecall()
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);;
	SetConsoleTitleA("Pixel Strike Base By 0SD47");
	const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("Base address: 0x%p\n", (void*)Base);
	printf("Process ID: %lu\n", pid);
	IL2CPP::Initialize();
	Hooks();


}









DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			safecall();
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}


BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}
