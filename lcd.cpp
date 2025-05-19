#include "pch.h"
#include "lcd.h"
#if __has_include("lcd.g.cpp")
#include "lcd.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::lcd_sandbox_c_test::implementation
{
    int32_t lcd::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void lcd::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void lcd::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
