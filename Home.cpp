#include "pch.h"
#include "Home.h"
#if __has_include("Home.g.cpp")
#include "Home.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UwpTemplate::implementation
{
    Home::Home()
    {
        InitializeComponent();
    }
}
