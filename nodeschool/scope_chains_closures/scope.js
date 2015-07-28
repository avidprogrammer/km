function foo() {
  var bar;
  quux = 1;
  function zip() {
    bar = true;
    var quux = 2;
  }
  return zip;
}
