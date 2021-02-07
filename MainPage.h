#pragma once

#include "MainPage.g.h"

namespace winrt::UwpTemplate::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        void NavView_BackRequested(winrt::Windows::UI::Xaml::Controls::NavigationView const& sender, winrt::Windows::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args);
        void NavView_ItemInvoked(winrt::Windows::UI::Xaml::Controls::NavigationView const& sender, winrt::Windows::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args);

    private:
        void GoBack();
        void Navigate(winrt::Windows::UI::Xaml::Interop::TypeName const& typeName);
    };
}

namespace winrt::UwpTemplate::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
