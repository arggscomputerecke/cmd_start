 $logfile =  "$env:APPDATA\..\Local\choco_update\update.log"
 $logfile_latest =  "$env:APPDATA\..\Local\choco_update\update_latest.log"
 
 set-content $logfile_latest "<startUpdate>"
  Add-Content  $logfile "<startUpdate>"
 $a = choco upgrade all --noop
 $b = 0;
$list = New-Object System.Collections.ArrayList;




 $date = Get-Date
 Add-Content  $logfile "  <date>$date</date>"
 add-content $logfile_latest "  <date>$date</date>"
 foreach($i in $a){ 
    if($i -eq "Can upgrade:") { 
        $b=1 ;
        
        continue;
        
        
    } 
    
    if($b){ 
         $prog = $i.split(" ")[2];
        $list.Add($prog);
    }
}

 foreach($i in $list){ 
    $prog = $i.split(".")[0]
    $c="$prog*"
    write-host $c
    $a = Get-Process "$prog*"
     Add-Content  $logfile "  <Programm>"
     add-content $logfile_latest "  <Programm>"
     Add-Content  $logfile "    <name>$prog</name>"
     add-content $logfile_latest "    <name>$prog</name>"
     
     
  if($a.count -eq 0){
   Add-Content  $logfile "    <RUN_choco_upgrade>"
   add-content $logfile_latest "    <RUN_choco_upgrade>"
    $log= choco upgrade $prog  -y 
    Add-Content  $logfile $log
     add-content $logfile_latest $log
    
    Add-Content  $logfile "    </RUN_choco_upgrade>"
    add-content $logfile_latest "    </RUN_choco_upgrade>"
  }
     Add-Content  $logfile "  </Programm>"
     add-content $logfile_latest "  </Programm>"
 }
 
 Add-Content  $logfile "</startUpdate>"
 add-content $logfile_latest "</startUpdate>"
 