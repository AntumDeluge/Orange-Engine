var TreeMenuItemComponent;
var TreeMenuComponent;
var TreeMenuNodeComponent;
var menuItems;
var callbackFunc;

function startUp() {
  TreeMenuItemComponent = Qt.createComponent("TreeMenuItem.qml");
  TreeMenuComponent = Qt.createComponent("TreeMenu.qml");
  TreeMenuNodeComponent = Qt.createComponent("TreeMenuNode.qml");
  menuItems = new Array();
}
