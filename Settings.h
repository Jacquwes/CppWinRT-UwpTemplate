#pragma once

#include "Settings.g.h"

namespace winrt::UwpTemplate::implementation
{
    struct Settings : SettingsT<Settings>
    {
        Settings();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::UwpTemplate::factory_implementation
{
    struct Settings : SettingsT<Settings, implementation::Settings>
    {
    };
}
