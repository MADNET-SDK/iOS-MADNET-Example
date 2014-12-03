(function()
 {
     var mraid = window.mraid = window.ormma;
     mraid.isViewable = function()
     {
         return ormma.getViewable();
	 };

     mraid.getVersion = function()
     {
         return "2.0";
	 };

	 mraid.createCalendarEvent = function(parameters)
	 {
		 return ormma._createCalendarEvent(parameters);
	 };
 })();
