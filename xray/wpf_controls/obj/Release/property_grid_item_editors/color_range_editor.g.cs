﻿#pragma checksum "..\..\..\property_grid_item_editors\color_range_editor.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "07446F0BF0297DDE2233C6294B1A7B23"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.4016
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms.Integration;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using xray.editor.wpf_controls;


namespace xray.editor.wpf_controls.property_grid_item_editors {
    
    
    /// <summary>
    /// color_range_editor
    /// </summary>
    public partial class color_range_editor : System.Windows.Controls.UserControl, System.Windows.Markup.IComponentConnector {
        
        
        #line 17 "..\..\..\property_grid_item_editors\color_range_editor.xaml"
        internal System.Windows.Controls.Button expand;
        
        #line default
        #line hidden
        
        
        #line 23 "..\..\..\property_grid_item_editors\color_range_editor.xaml"
        internal System.Windows.Controls.Button collapse;
        
        #line default
        #line hidden
        
        
        #line 32 "..\..\..\property_grid_item_editors\color_range_editor.xaml"
        internal System.Windows.Controls.StackPanel item_text_panel;
        
        #line default
        #line hidden
        
        
        #line 53 "..\..\..\property_grid_item_editors\color_range_editor.xaml"
        internal System.Windows.Controls.Border body;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/wpf_controls;component/property_grid_item_editors/color_range_editor.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\property_grid_item_editors\color_range_editor.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.expand = ((System.Windows.Controls.Button)(target));
            
            #line 17 "..\..\..\property_grid_item_editors\color_range_editor.xaml"
            this.expand.Click += new System.Windows.RoutedEventHandler(this.expand_collapse_Click);
            
            #line default
            #line hidden
            return;
            case 2:
            this.collapse = ((System.Windows.Controls.Button)(target));
            
            #line 23 "..\..\..\property_grid_item_editors\color_range_editor.xaml"
            this.collapse.Click += new System.Windows.RoutedEventHandler(this.expand_collapse_Click);
            
            #line default
            #line hidden
            return;
            case 3:
            this.item_text_panel = ((System.Windows.Controls.StackPanel)(target));
            return;
            case 4:
            this.body = ((System.Windows.Controls.Border)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}
