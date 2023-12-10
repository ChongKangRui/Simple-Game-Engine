
$templateName = (Get-ChildItem "*.sln").BaseName;

Write-Host "Rename project"$templateName" to";

$ProjName = Read-Host -Prompt 'Input Project Name'

# Rename solution and replace inside
Rename-Item $templateName".sln" -NewName $ProjName".sln";

(Get-Content $ProjName".sln") |
ForEach-Object {$_ -replace $templateName, $ProjName} |
Out-File $ProjName".sln";

# Rename project folder
$NewProjectDirectoryName = $ProjName+"\";
Rename-Item $templateName"\" -NewName $ProjName

$vcxproj = $NewProjectDirectoryName+$templateName+".vcxproj"
$projFilters = $NewProjectDirectoryName+$templateName+".vcxproj.filters"
$projUser = $NewProjectDirectoryName+$templateName+".vcxproj.user"

# Rename .vcxproj* files
Rename-Item $vcxproj -NewName $ProjName".vcxproj";
Rename-Item $projFilters -NewName $ProjName".vcxproj.filters";
Rename-Item $projUser -NewName $ProjName".vcxproj.user";

(Get-Content $NewProjectDirectoryName$ProjName".vcxproj") |
ForEach-Object {$_ -replace $templateName, $ProjName} |
Out-File $NewProjectDirectoryName$ProjName".vcxproj";



