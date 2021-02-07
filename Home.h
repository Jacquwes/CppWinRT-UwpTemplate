#pragma once

#include "Home.g.h"

namespace winrt::UwpTemplate::implementation
{
    struct Home : HomeT<Home>
    {
        Home();
    };
}

namespace winrt::UwpTemplate::factory_implementation
{
    struct Home : HomeT<Home, implementation::Home>
    {
    };
}
