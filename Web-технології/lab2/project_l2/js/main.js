window.onload = function() {
  
  var app_ws = document.getElementById("app");  
  var rh = new RequestHandler();
  var comHndl = new CommentHandler(app_ws, rh);  
}