<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>

<head>
    <title>�ڵ� �������� ����� ���� �¶��� ���� �ý���</title>
    <meta charset="UTF-8">
    <title>�������׸��</title>
    
    <link href="/css/customer/layout.css" type="text/css" rel="stylesheet" />
    <style>
    
        #visual .content-container{	
            height:inherit;
            display:flex; 
            align-items: center;
            
            background: url("../../images/customer/visual.png") no-repeat center;
        }
    </style>
</head>

<body>
    <!-- header �κ� -->

    <header id="header">
        
        <div class="content-container">
            <!-- ---------------------------<header>--------------------------------------- -->

            <h1 id="logo">
                <a href="/index.html">
                    <img src="/images/logo.png" alt="����ó �¶���" />

                </a>
            </h1>

            <section>
                <h1 class="hidden">���</h1>

                <nav id="main-menu">
                    <h1>���θ޴�</h1>
                    <ul>
                        <li><a href="/guide">�н����̵�</a></li>

                        <li><a href="/course">���¼���</a></li>
                        <li><a href="/answeris/index">AnswerIs</a></li>
                    </ul>
                </nav>

                <div class="sub-menu">

                    <section id="search-form">
                        <h1>���°˻� ��</h1>
                        <form action="/course">
                            <fieldset>
                                <legend>�����˻��ʵ�</legend>
                                <label>�����˻�</label>
                                <input type="text" name="q" value="" />
                                <input type="submit" value="�˻�" />
                            </fieldset>
                        </form>
                    </section>

                    <nav id="acount-menu">
                        <h1 class="hidden">ȸ���޴�</h1>
                        <ul>
                            <li><a href="/index.html">HOME</a></li>
                            <li><a href="/member/login.html">�α���</a></li>
                            <li><a href="/member/agree.html">ȸ������</a></li>
                        </ul>
                    </nav>

                    <nav id="member-menu" class="linear-layout">
                        <h1 class="hidden">���޴�</h1>
                        <ul class="linear-layout">
                            <li><a href="/member/home"><img src="/images/txt-mypage.png" alt="����������" /></a></li>
                            <li><a href="/notice/list.html"><img src="/images/txt-customer.png" alt="������" /></a></li>
                        </ul>
                    </nav>

                </div>
            </section>

        </div>
        
    </header>

	<!-- --------------------------- <visual> --------------------------------------- -->
	<!-- visual �κ� -->
	
	<div id="visual">
		<div class="content-container"></div>
	</div>
	<!-- --------------------------- <body> --------------------------------------- -->
	<div id="body">
		<div class="content-container clearfix">

			<!-- --------------------------- aside --------------------------------------- -->
			<!-- aside �κ� -->


			<aside class="aside">
				<h1>������</h1>

				<nav class="menu text-menu first margin-top">
					<h1>�����͸޴�</h1>
					<ul>
						<li><a class="current"  href="/customer/notice">��������</a></li>
						<li><a class=""  href="/customer/faq">�����ϴ� ����</a></li>
						<li><a class="" href="/customer/question">��������</a></li>
						<li><a class="" href="/customer/event">�̺�Ʈ</a></li>
						
					</ul>
				</nav>


	<nav class="menu">
		<h1>���¾�ü</h1>
		<ul>
			<li><a target="_blank" href="http://www.notepubs.com"><img src="/images/notepubs.png" alt="��Ʈ�ེ" /></a></li>
			<li><a target="_blank" href="http://www.namoolab.com"><img src="/images/namoolab.png" alt="������������" /></a></li>
						
		</ul>
	</nav>
					
			</aside>
			<!-- --------------------------- main --------------------------------------- -->



		<main class="main">
			<h2 class="main title">��������</h2>
			
			<div class="breadcrumb">
				<h3 class="hidden">���</h3>
				<ul>
					<li>home</li>
					<li>������</li>
					<li>��������</li>
				</ul>
			</div>
			
			<div class="search-form margin-top first align-right">
				<h3 class="hidden">�������� �˻���</h3>
				<form class="table-form">
					<fieldset>
						<legend class="hidden">�������� �˻� �ʵ�</legend>
						<label class="hidden">�˻��з�</label>
						<select name="f">
							<option  value="title">����</option>
							<option  value="writerId">�ۼ���</option>
						</select> 
						<label class="hidden">�˻���</label>
						<input type="text" name="q" value=""/>
						<input class="btn btn-search" type="submit" value="�˻�" />
					</fieldset>
				</form>
			</div>
			
			<div class="notice margin-top">
				<h3 class="hidden">�������� ���</h3>
				<table class="table">
					<thead>
						<tr>
							<th class="w60">��ȣ</th>
							<th class="expand">����</th>
							<th class="w100">�ۼ���</th>
							<th class="w100">�ۼ���</th>
							<th class="w60">��ȸ��</th>
						</tr>
					</thead>
					<tbody>
							
					<tr>
						<td>8</td>
						<td class="title indent text-align-left"><a href="detail">������ 8�������� ���� �ڵ�</a></td>
						<td>newlec</td>
						<td>
							2019-08-18		
						</td>
						<td>146</td>
					</tr>
							
					<tr>
						<td>7</td>
						<td class="title indent text-align-left"><a href="detail.html">������ DI ���� �ڵ�</a></td>
						<td>newlec</td>
						<td>
							2019-08-15		
						</td>
						<td>131</td>
					</tr>
							
					<tr>
						<td>6</td>
						<td class="title indent text-align-left"><a href="detail.html">������ 9�� �� ������� ���� �ȳ�</a></td>
						<td>newlec</td>
						<td>
							2019-06-11		
						</td>
						<td>517</td>
					</tr>
							
					<tr>
						<td>5</td>
						<td class="title indent text-align-left"><a href="detail.html">����ó ���� ���� ��� �ȳ�</a></td>
						<td>newlec</td>
						<td>
							2019-05-24		
						</td>
						<td>448</td>
					</tr>
							
					<tr>
						<td>4</td>
						<td class="title indent text-align-left"><a href="detail.html">�ڹ� �������� ���α׷��� ���� ���� ����</a></td>
						<td>newlec</td>
						<td>
							2019-04-24		
						</td>
						<td>520</td>
					</tr>
					
					
					</tbody>
				</table>
			</div>
			
			<div class="indexer margin-top align-right">
				<h3 class="hidden">���� ������</h3>
				<div><span class="text-orange text-strong">1</span> / 1 pages</div>
			</div>

			<div class="margin-top align-center pager">	
		
	<div>
		
		
		<span class="btn btn-prev" onclick="alert('���� �������� �����ϴ�.');">����</span>
		
	</div>
	<ul class="-list- center">
		<li><a class="-text- orange bold" href="?p=1&t=&q=" >1</a></li>
				
	</ul>
	<div>
		
		
			<span class="btn btn-next" onclick="alert('���� �������� �����ϴ�.');">����</span>
		
	</div>
	
			</div>
		</main>
		
			
		</div>
	</div>

    <!-- ------------------- <footer> --------------------------------------- -->



        <footer id="footer">
            <div class="content-container">
                <h2 id="footer-logo"><img src="/images/logo-footer.png" alt="ȸ������"></h2>
    
                <div id="company-info">
                    <dl>
                        <dt>�ּ�:</dt>
                        <dd>����Ư���� </dd>
                        <dt>�����ڸ���:</dt>
                        <dd>admin@newlecture.com</dd>
                    </dl>
                    <dl>
                        <dt>����� ��Ϲ�ȣ:</dt>
                        <dd>111-11-11111</dd>
                        <dt>��� �Ǹž�:</dt>
                        <dd>�Ű��� 1111 ȣ</dd>
                    </dl>
                    <dl>
                        <dt>��ȣ:</dt>
                        <dd>����ó</dd>
                        <dt>��ǥ:</dt>
                        <dd>ȫ�浿</dd>
                        <dt>��ȭ��ȣ:</dt>
                        <dd>111-1111-1111</dd>
                    </dl>
                    <div id="copyright" class="margin-top">Copyright �� newlecture.com 2012-2014 All Right Reserved.
                        Contact admin@newlecture.com for more information</div>
                </div>
            </div>
        </footer>
    </body>
    
    </html>