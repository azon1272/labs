function CommentHandler (parent, requestHandler) {

	this.rh = requestHandler;
  	var commentArea = document.createElement("INPUT");  
  	commentArea.setAttribute("type", "text");
  	parent.appendChild(commentArea);

  	commentArea.onkeypress =  function(self)  {
  		return function(event) {
			var keyCode = ('which' in event) ? event.which : event.keyCode;
		    if (keyCode == 13) {
		    	//https://maps.googleapis.com/maps/api/distancematrix/json?origins='Mykolaiv, Mykolaivs'ka oblast, Ukraine'&destinations='Kiev, Kyiv city, Ukraine'&sensor=false
		    	self.rh.getUrl(
              "/project_l2/src/coordinates.php?origin='Kiev, Kiev City'",
		    		{},
		    	self.onSuccess);
		    }
		};
  	}(this);

  	
}

CommentHandler.prototype.onKeyPress = function(event) {
	var keyCode = ('which' in event) ? event.which : event.keyCode;
    if (keyCode == 13) {
    	trh.getUrl(
      
        {},
      	this.onSuccess
      );
      }
    }
};

CommentHandler.prototype.onSuccess = function(par1, par2, par3) {
	alert("aaaa")
}