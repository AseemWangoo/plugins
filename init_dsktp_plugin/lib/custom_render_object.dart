import 'package:flutter/rendering.dart';

import 'package:flutter/widgets.dart';

class CustomCenter extends SingleChildRenderObjectWidget {
  CustomCenter({Key key, Widget child}) : super(key: key, child: child);

  @override
  RenderObject createRenderObject(BuildContext context) =>
      _CustomCenterRenderer();
}

/// [RenderObjectWithChildMixin] a Mixin implemented by the RenderBox
/// ```dart
/// class RenderFoo extends RenderBox
///   with RenderObjectWithChildMixin<RenderBar> {
///   // ...
/// }
class _CustomCenterRenderer extends RenderBox
    with RenderObjectWithChildMixin<RenderBox> {
  @override
  void performLayout() {
    if (child != null) {
      ///
      /// [parentUsesSize] : WHen the widget changes, we also need to
      /// change the parent..
      child.layout(constraints.loosen(), parentUsesSize: true);

      size = constraints.biggest;

      /// Formulae to calculate the middle...
      double _dx = (constraints.maxWidth - child.size.width) / 2;
      double _dy = (constraints.maxHeight - child.size.height) / 2;

      /// Store the above information now.....
      BoxParentData _parentData = child.parentData;
      _parentData.offset = Offset(_dx, _dy);
    } else {
      /// We want our widget to be as small as possible, in case
      /// no child is specified..
      size = Size.zero;
    }
  }

  @override
  void paint(PaintingContext context, Offset offset) {
    if (child != null) {
      BoxParentData _parentData = child.parentData as BoxParentData;
      context.paintChild(child, offset + _parentData.offset);
    }
  }
}
