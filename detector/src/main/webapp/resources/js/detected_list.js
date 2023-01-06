function page(){
    $('table.paginated').each(function() {
        var numPage = 10;
        var currentPage = 0;
        var numPerPage = 5;
        var $table = $(this);
        var pagination = $("#pagination");
        var numRows = $table.find('tr').length;
        var numPages = Math.ceil(numRows / numPerPage);
        if (numPages==0) return;
        var $pager = $('<div class="pager"></div>');
        var nowp = currentPage;
        var endp = nowp+10;
        $table.bind('repaginate', function() {
            $table.find('tr').hide().slice(currentPage * numPerPage, (currentPage + 1) * numPerPage).show();
            $("#pagination").html("");
            if (numPages > 1) {
                if (currentPage < 5 && numPages-currentPage >= 5) {
                    nowp = 0;
                    endp = numPage;
                } else {
                    nowp = currentPage -5;
                    endp = nowp+numPage;
                    pi = 1;
                }
                if (numPages < endp) {
                    endp = numPages;
                    nowp = numPages-numPage;
                }
                if (nowp < 1) {
                    nowp = 0;
                }
            } else {
                nowp = 0;
                endp = numPages;
            }
            $('<span class="pageNum first">≪ </span>').bind('click', {newPage: page},function(event) {
                currentPage = 0;
                $table.trigger('repaginate');
                $($(".pageNum")[2]).addClass('active').siblings().removeClass('active');
            }).appendTo(pagination).addClass('clickable');
            $('<span class="pageNum back">< </span>').bind('click', {newPage: page},function(event) {
                if(currentPage == 0) return;
                currentPage = currentPage-1;
                $table.trigger('repaginate');
                $($(".pageNum")[(currentPage-nowp)+2]).addClass('active').siblings().removeClass('active');
            }).appendTo(pagination).addClass('clickable');
            for (var page = nowp ; page < endp; page++) {
                $('<span class="pageNum"></span>').text((page + 1).toString() + ' ').bind('click', {newPage: page}, function(event) {
                    currentPage = event.data['newPage'];
                    $table.trigger('repaginate');
                    $($(".pageNum")[(currentPage-nowp)+2]).addClass('active').siblings().removeClass('active');
                }).appendTo(pagination).addClass('clickable');
            }
            $('<span class="pageNum next"> ></span>').bind('click', {newPage: page},function(event) {
                if(currentPage == numPages-1) return;
                currentPage = currentPage+1;
                $table.trigger('repaginate');
                $($(".pageNum")[(currentPage-nowp)+2]).addClass('active').siblings().removeClass('active');
            }).appendTo(pagination).addClass('clickable');
            $('<span class="pageNum last"> ≫</span>').bind('click', {newPage: page},function(event) {
                currentPage = numPages-1;
                $table.trigger('repaginate');
                $($(".pageNum")[endp-nowp+1]).addClass('active').siblings().removeClass('active');
            }).appendTo(pagination).addClass('clickable');
            $($(".pageNum")[2]).addClass('active');
        });
        $pager.insertAfter($table).find('span.pageNum:first').next().next().addClass('active');
        $pager.appendTo(pagination);
        $table.trigger('repaginate');
    });
}

function modal() {
	let img_base = "//192.168.0.103/imgs/"
	$(".popup").click(function () {
		$(".img_detail").attr("src", img_base + this.getAttribute("data-i_img_name"));
		$(".i_no").text(this.getAttribute("data-i_no"));
		$(".i_device").text(this.getAttribute("data-i_device"));
		$(".i_img_name").text(this.getAttribute("data-i_img_name"));
		$(".i_reg_date").text(this.getAttribute("data-i_reg_date").replace("+", " "));
		$(".modal").toggleClass("show");
		if ($(".modal").hasClass("show")) {
			$("body").css("overflow", "hidden");
		}
	});
	
	$(".modal").click(function() {
		$(".modal.show").toggleClass("show");
		if (!$(".modal").hasClass("show")) {
			$("body").css("overflow","auto");
		}
	});
}

function ajax(){
	$('#searchMonthly').click(function(){
		var month = $('.month').val();
		var data = {'month' : month,};
		var hostIndex = location.href.indexOf(location.host) + location.host.length;
		var contextPath = location.href.substring( hostIndex, location.href.indexOf("/", hostIndex + 1) );
		$.ajax({
		    type: 'POST',
		    url: contextPath + "/ajaxMonthly",
		    data: JSON.stringify(data),
		    dataType : 'JSON',
		    contentType: "application/json",
		    success: function(data){
		        if (data.length > 0) {
		            var tblRow = "<tbody>";
		        	for (var i = 0; i < data.length; i++){
		                if (i % 5 == 0) {
		                    tblRow += "<tr>";
		                }
		                tblRow += "<td><a href='#none' class='popup' ";
		                tblRow += "data-i_no=" + data.at(i).i_no + " ";
		                tblRow += "data-i_device=" + data.at(i).i_device + " ";
		                tblRow += "data-i_img_name=" + data.at(i).i_img_name + " ";
		                tblRow += "data-i_reg_date=" + data.at(i).i_reg_date.replace(" ", "+") + ">";
		                tblRow += "<img title='" + data.at(i).i_reg_date + "' src='//192.168.0.103/imgs/" + data.at(i).i_img_name + "' width='126' /></a></td>";
		                if (i % 5 == 4) {
		                    tblRow += "</tr>";
		                }
		                if (data.length - 1 == i && i % 5 != 4){
							tblRow += "</tr>";
						}
		            }
		            tblRow += "</tbody>";
		            $(".paginated").empty();
		            $(".paginated").append(tblRow);
		        } else {
		            alert("내역 없음.");
		        }
		        page();
		        modal();
		    },
		    error: function(request, status, error){
		        alert("검색 실패.");
		    }
		})
	});

	$('#searchDaily').click(function(){
	    var day = $('.day').val();
	    var data = {'day':day}
	    var hostIndex = location.href.indexOf(location.host) + location.host.length;
		var contextPath = location.href.substring( hostIndex, location.href.indexOf("/", hostIndex + 1) );
	    $.ajax({
	        type: 'POST',
	        url: contextPath + "/ajaxDaily",
	        data: JSON.stringify(data),
	        dataType : 'JSON',
	        contentType: "application/json",
	        success: function(data){
	            if (data.length > 0) {
	                var tblRow = "<tbody>";
	                for (var i = 0; i < data.length; i++){
		                if (i % 5 == 0) {
		                    tblRow += "<tr>";
		                }
		                tblRow += "<td><a href='#none' class='popup' ";
		                tblRow += "data-i_no=" + data.at(i).i_no + " ";
		                tblRow += "data-i_device=" + data.at(i).i_device + " ";
		                tblRow += "data-i_img_name=" + data.at(i).i_img_name + " ";
		                tblRow += "data-i_reg_date=" + data.at(i).i_reg_date.replace(" ", "+") + ">";
		                tblRow += "<img title='" + data.at(i).i_reg_date + "' src='//192.168.0.103/imgs/" + data.at(i).i_img_name + "' width='126' /></a></td>";
		                if (i % 5 == 4) {
		                    tblRow += "</tr>";
		                }
		                if (data.length - 1 == i && i % 5 != 4){
							tblRow += "</tr>";
						}
		            }
		            tblRow += "</tbody>";
		            $(".paginated").empty();
		            $(".paginated").append(tblRow);
	            } else {
	                alert("내역 없음.");
	            }
	            page();
	            modal();
	        },
	        error: function(request, status, error){
	            alert("검색 실패.");
	        }
	    })
	});
	
	
}

$(function() {
	page();
	modal();
	ajax();
});


