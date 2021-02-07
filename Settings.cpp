#include "pch.h"
#include "Settings.h"
#if __has_include("Settings.g.cpp")
#include "Settings.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UwpTemplate::implementation
{
    Settings::Settings()
    {
        InitializeComponent();
    }

    int32_t Settings::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Settings::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void Settings::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
