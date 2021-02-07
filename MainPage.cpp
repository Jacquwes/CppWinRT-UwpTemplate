#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UwpTemplate::implementation
{
	MainPage::MainPage()
	{
		InitializeComponent();

		Navigate({ L"UwpTemplate.Home", Interop::TypeKind::Primitive });
	}

	void MainPage::NavView_BackRequested(Controls::NavigationView const& sender, Controls::NavigationViewBackRequestedEventArgs const& args) { GoBack(); }

	void MainPage::NavView_ItemInvoked(Controls::NavigationView const& sender, Controls::NavigationViewItemInvokedEventArgs const& args)
	{
		Navigate({ args.IsSettingsInvoked()
			? L"UwpTemplate.Settings"
			: unbox_value<hstring>(args.InvokedItemContainer().Tag()),
			Interop::TypeKind::Primitive });
	}

	/// <summary>
	/// Navigate back to the last page. Handles the navigationview backbutton toggling and selected item.
	/// </summary>
	void MainPage::GoBack()
	{
		if (MainFrame().CanGoBack())
			MainFrame().GoBack();

		NavView().IsBackEnabled(MainFrame().CanGoBack());

		for (auto&& i : NavView().MenuItems())
			if (i.as<Controls::NavigationViewItem>().Tag().as<hstring>() == MainFrame().CurrentSourcePageType().Name)
			{
				NavView().SelectedItem(i);
				return;
			}

		NavView().SelectedItem(NavView().SettingsItem());
	}

	/// <summary>
	/// Used to navigate through pages. Handles the navigationview backbutton toggling and selected item.
	/// </summary>
	/// <param name="typeName">Type of the target page</param>
	void MainPage::Navigate(Interop::TypeName const& typeName)
	{
		if (MainFrame().CurrentSourcePageType().Name == typeName.Name)
			return;
		MainFrame().Navigate(typeName);

		NavView().IsBackEnabled(MainFrame().CanGoBack());

		for (auto&& i : NavView().MenuItems())
			if (i.as<Controls::NavigationViewItem>().Tag().as<hstring>() == typeName.Name)
			{
				NavView().SelectedItem(i);
				break;
			}
	}
}