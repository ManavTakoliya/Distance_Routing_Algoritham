<!DOCTYPE html>
<html>
<head>
  
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title></title>
  <!-- Tell the browser to be responsive to screen width -->
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

</head>

<body style=" background-image: url('image1.jpg'); class="hold-transition sidebar-mini">
  
  <div class="content-wrapper">
    <div class="container">
      
      <div class="row">

        <div class="col-12">
            
          <div class="card mt-5 mb-5">
 
            <div class="card-header text-center">
              <h3 class="card-title">ROUTING TABLES</h3>
            </div>

            <div class="card-body">

              
              <?php

                $arr = array("N1","N2","N3","N4","N5","N6","N7");

                $file = fopen("../rt.csv","r");
                $data = fgetcsv($file);
                
                $n = (int)$data[0];

                for ($x = 1; $x <= $n; $x+=1) {

                ?>

                  <table class="table table-striped">
                  <thead class="thead-dark">
                    <tr>
                      <th scope="col">Destination</th>
                      <th scope="col">Distance</th>
                      <th scope="col">Via</th>
                    </tr>
                  </thead>

                  <tbody>

                    <?php
                      
                      while(($data = fgetcsv($file))!==false){

                      $temp = (int)$data[0];
                      if($x == $temp){
                          break;
                      }

                      echo "<tr>";
                        foreach($data as $i){
                          echo "<td>".htmlspecialchars($i)."</td>";
                        }
                      echo "</tr>\n";
                      }
                    ?>
                      
                  </tbody>
                </table>

                <?php
                  }
                ?>
                  
        

              
                
      
            
            </div>

          </div>
        </div>

      </div>
    </div>    
  </div>

      <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
      <script src="https://cdn.jsdelivr.net/npm/popper.js@1.12.9/dist/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
      <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
        


</body>
</html>
